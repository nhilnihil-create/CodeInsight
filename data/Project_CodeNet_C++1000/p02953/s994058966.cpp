#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,tmp=0;
    bool ok=true;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h.at(i);
    }
    reverse(h.begin(),h.end());
    for(int i=0;i<n;i++){
        if(i==0)tmp=h.at(i);
        else{
            if(tmp+1<h.at(i)){ok=false;break;}
            else{
                tmp=min(tmp,h.at(i));
            }
        }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}