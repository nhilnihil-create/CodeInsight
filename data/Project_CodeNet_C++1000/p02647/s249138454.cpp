#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        vector<int> b(n+1);
        for(int j=0;j<n;j++){
            int left=max(0,j-a[j]);
            int right=min(n,j+a[j]+1);
            b[left]++;b[right]--;
        }
        for(int j=0;j<n;j++){
            b[j+1]+=b[j];
        }
        b.pop_back();
        if(a==b) break;
        a=b;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}