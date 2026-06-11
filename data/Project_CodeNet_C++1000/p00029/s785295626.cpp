#include <cstdio>
#include <string>
#include <map>
using namespace std;
typedef map<string, int> MyMap;

MyMap hash;

void print_map(char* msg, int begin, int end) {
	char t_msg[1001] = {'\0'};
	string t_str;
	int cnt = 0;
	
	for (int i = begin; i < end; i++) {
		t_msg[cnt] = msg[i];
		cnt++;
	}
	t_msg[end] = '\0';
	
	t_str = string(t_msg);
	// Key isnt exist.
	if ((int)hash.count(t_str) == 0) {
		hash.insert(MyMap::value_type(t_str, 1));
	}
	// Key is exist. (return number is 1.)
	else {
		hash[t_str]++;
	}
}

int main(int argc, char *argv[]) {
	char msg[1001];
	fgets(msg, 1001, stdin);
	// Load
	int cnt = 0;
	for (int i = 0; i < 1001; i++) {
		if (msg[i] == '\n') {
			print_map(msg, cnt, i);
			break;
		}
		if (msg[i] == ' ') {
			print_map(msg, cnt, i);
			cnt = i+1;
		}
	}
	// Map print
	MyMap::iterator itr = hash.begin();
	MyMap::iterator max_sz_itr;
	MyMap::iterator max_fq_itr;
	int max_str_size = 0;
	int max_freq = 0;
	while (itr != hash.end()) {
		// max size
		if ((*itr).second > max_str_size) {
			max_str_size = (*itr).second;
			max_sz_itr = itr;
		}
		// max freq
		int t_freq = static_cast<int>((*itr).first.size());
		if (t_freq > max_freq) {
			max_freq = t_freq;
			max_fq_itr = itr;
		}
		itr++;
	}
	// print
	printf("%s %s\n",
	(*max_sz_itr).first.c_str(), (*max_fq_itr).first.c_str());
	return 0;
}