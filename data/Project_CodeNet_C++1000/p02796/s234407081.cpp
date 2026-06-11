#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin>>n;
    pair<int,int> rl[n];
    for(int i=0; i<n;i++){
        int x,l;
        cin>>x>>l;
        rl[i] = make_pair(x+l,x-l);
    }

    sort(rl,rl+n);

    int right = -1000000000,ans=0;
    for(int i=0;i<n;i++){
        if(right <= rl[i].second){
            ans ++;
            right = rl[i].first;
        }
    }
    cout<<ans<<endl;
}