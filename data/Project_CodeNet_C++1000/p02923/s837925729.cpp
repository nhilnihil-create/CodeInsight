#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int count=0; int height=h[0];
    int max_count=0;
    for(int i=1; i<n; i++){
        if(height>=h[i]){
            count++; height = h[i];
        }else{
            if(count>max_count)
                max_count = count;
            count =0 ;
            height = h[i];
        }
    }
    if(count > max_count)
        max_count = count;
    cout << max_count << endl;

    return 0;
}
