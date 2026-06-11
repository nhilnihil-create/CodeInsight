#include <iostream>
using namespace std;
int main(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    char ex='A';
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]==ex)ans++;
        else ex=s[i];
    }
    cout << min(ans+2*k,n-1);
    return 0;
}