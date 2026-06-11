#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<long long>vec(N);
    long long left=0;
    long long right=0;
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
        left+=vec.at(i);
    }
    long long minn=999999999999999999;
    for(int i=N-1;i>=0;i--){
        left-=vec.at(i);
        right+=vec.at(i);
     long long zettai=abs(left-right);
         minn=min(minn,zettai);
    }
    cout <<minn<<endl;
}