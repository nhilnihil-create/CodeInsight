#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i=0;i<n;i++) cin >> l[i];
    sort(l.begin(),l.end());

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int c = l[i]+l[j];
            auto itr = lower_bound(l.begin(),l.end(),c);
            cnt += (int)(itr-(l.begin()+j)-1);
        }
    }

    cout << cnt << endl;
    return 0;

}