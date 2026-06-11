#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    if(n<=2){}
    else{
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(a.at(i)==a.at(j)||a.at(i)==a.at(k)||a.at(j)==a.at(k))continue;
                    int dekai=max(a.at(i),max(a.at(j),a.at(k)));
                    if(a.at(i)+a.at(j)+a.at(k)-2*dekai>0)ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}