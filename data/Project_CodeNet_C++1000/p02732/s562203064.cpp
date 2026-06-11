#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<long long,long long> mp;
    vector<long long> va(n);
    for(int i=0;i<n;i++){
        long long a;
        cin >> a;
        mp[a]++;
        va[i]=a;
    }
    long long all=0;
    for(auto x: mp){
        all+=x.second*(x.second-1)/2;
    }
    long long diff;
    for(int i=0;i<n;i++){
        diff=mp[va[i]]-1;
        cout << all-diff << endl;
    }
    return 0;
}