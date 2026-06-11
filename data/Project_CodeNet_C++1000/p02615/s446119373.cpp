#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lld = long long int ;
#define mod 1000000007; 

int main(){
    lld N;
    cin >> N ;
    vector<int > A;
    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    sort(A.begin(),A.end());
    
    lld k=0;
    lld  ans=0;
    for(int i=1;i<N;i++){
        k=i/2;
        ans+=A[N-1-k];
    }
    cout << ans <<endl;
    return 0;
    return 0;
}