#include<iostream>
using namespace std;

int main() {
    int n,m,p;
    while(cin>>n>>m>>p,n||m||p){
        int ch[100],mm=0,ans;
        for(int i=1;i<=n;i++){
            cin >> ch[i];
            mm+=ch[i];
        }
        mm*=100;
        if(ch[m]==0) cout << ch[m] << endl;
        else{
            mm=mm*(100-p)/100;
            ans=mm/ch[m];
            cout << ans << endl;
        }
    }
    return 0;
}