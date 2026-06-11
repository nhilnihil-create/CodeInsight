#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<long> A(N);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    long mini = A[0], maxi = A[N-1];
    vector<long> minarr, pluarr;
    for(int i=1;i<N-1;++i){
        if(A[i]>=0){
            pluarr.push_back(A[i]);
            mini -= A[i];
        }
        else {
            minarr.push_back(A[i]);
            maxi -= A[i];
        }
    }
    cout<<maxi - mini<<endl;
    maxi = A[N-1];
    mini = A[0];
    for(int i=0;i<minarr.size();++i){
        cout<<maxi<<" "<<minarr[i]<<endl;
        maxi -= minarr[i];
    }
    for(int i=0;i<pluarr.size();++i){
        cout<<mini<<" "<<pluarr[i]<<endl;
        mini -= pluarr[i];
    }
    cout<<maxi<<" "<<mini<<endl;
}
