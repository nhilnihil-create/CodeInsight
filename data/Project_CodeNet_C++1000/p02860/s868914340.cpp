#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    string s;
    cin >> n >> s;
    sort(s.begin(), s.end());
    for(int i=0; i<n; i+=2){
        if(s[i]==s[i+1]) ++cnt;
    }
    if(cnt==n/2 && n%2==0){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}
