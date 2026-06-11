#include <bits/stdc++.h>
using namespace std;
vector<int> dx= {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const int INF=100000000;

int main(){
    int h,w,n;
    cin>>h>>w>>n;
    int m=max(h,w);
    cout<<((n-1)/m)+1<<endl;
    return 0;

}
