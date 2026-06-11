#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    int N;
    cin >> N;
    vector<int> x(N,0);
    for(int i=0;i<N;i++)cin>>x[i];
    int res=INT32_MAX;
    for(int p=-1;p<102;p++){
        int total=0;
        for(int i=0;i<N;i++)total+=(x[i]-p)*(x[i]-p);
        res=min(total,res);
    }
    cout<<res;
    return 0;
}