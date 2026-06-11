#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int debug = 0;

int main(void){
	string tmp;
	string max_len_word, max_times_word;
	unsigned int max_len = 0, max_times = 0;
	map<string, int> words;

	while(cin >> tmp){
		if(tmp.size() > max_len){
			max_len_word = tmp;
			max_len = tmp.size();
			if(debug) cout << "longest word overwritten." << endl;
		}
		++words[tmp]; 
		if(debug) cout << "count " << tmp << " is " << words[tmp] << endl;
	}

	map<string, int>::iterator it;
	max_times=0;
	for(it=words.begin(); it!=words.end(); ++it){
		if(max_times < it->second){
			max_times_word = it->first;
			max_times = it->second;
			if(debug) cout << "the most frequent word is now" << it->first << endl;
		}
		if(debug) cout << "count " << it->first << " is " << it->second << endl;
	}

	cout << max_times_word << " " << max_len_word << endl;

	return 0;
}