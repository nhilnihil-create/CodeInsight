#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll N;
    ll i;
    vector<long long int> A;
    cin >> N;
    for(i=0;i<N;i++){
        ll ai;
        cin >> ai;
        A.push_back(ai);
    }

    ll count = 0;
    ll gap;
    ll ni, nii;
    nii = A[0];
    for(i=1;i<N;i++){
        ni = A[i];
        gap = nii - ni;
        if(gap > 0){
            count += gap;
            nii = ni + gap;
        }
        else{nii = ni;}
    }
    cout << count << endl;
    return 0;
}
