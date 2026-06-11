#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;
    double ans = 0;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(i);
    int x[n],y[n];
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    do{
        for(int i=0;i<v.size()-1;i++){
            int a = v[i],b = v[i+1];
            ans += sqrt(pow(x[a]-x[b],2)+pow(y[a]-y[b],2));
        }
        cnt++;
    }while(next_permutation(v.begin(),v.end()));
    cout <<fixed << setprecision(10) << ans/cnt << endl;
}