#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>



using namespace std;

string s;
int ans=0;

int main(){
    cin >> s;
    int n = s.size();
    for(int i=0;i<n/2;i++){
        //cout << s[i] << " " << s[n-i-1] << (s[i] == s[n-i-1]) << endl;;
        if(s[i] == s[n-i-1]) continue;
        else ans ++;
    }
    cout << ans << endl;
}