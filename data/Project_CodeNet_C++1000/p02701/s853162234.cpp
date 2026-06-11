#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;
int main() {
	int N;
	cin >> N;
	std::map<std::string, int> word;
	std::string S;
	for(int i = 0;i<N;i++){
		cin >> S;
		word[S]++;
	}
	
cout << word.size() << endl;
	return 0;
}
