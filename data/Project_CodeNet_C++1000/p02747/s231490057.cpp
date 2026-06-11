#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s;
	int j, count = 0;
	cin >> s;
	int n = s.size();
	if(n % 2 ==1) {
		cout << "No" << "\n";
		return 0;
	}
	for(int i = 0; i < n - 1; i = i + 2){
		
		string subs = s.substr(i, 2);
		if(subs == "hi"){
			count++;
		}
		
		
	}
	cout << (n / 2 == count ? "Yes" : "No") << "\n";
	return 0;
}

