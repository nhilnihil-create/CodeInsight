#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    int count = 0;
	int res = 2000;
    for(int i=0;i<=s.size()-t.size();i++){
        count=0;
        for(int j=0; j<t.size(); j++){
            if(s[i+j] != t[j]){
				count++;
			}
        }
        res = min(res,count);
    }
    cout << res;
}