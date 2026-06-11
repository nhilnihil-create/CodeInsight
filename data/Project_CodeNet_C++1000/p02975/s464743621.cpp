#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end());
    map<int,int> m;
    vector<int> l;
    rep(i,N){
        if(m[A[i]]==0){
            l.push_back(A[i]);
        }
        m[A[i]]++;
    }
    if(l.size()>3){
        cout << "No" << endl;
        return 0;
    }
    else if(l.size()==1){
        if(m[0]!=0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    else if(l.size()==2){
        if(N%3==0&&m[0]==N/3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    else if(l.size()==3){
        if(N%3==0&&m[l[0]]==N/3&&m[l[1]]==N/3&&m[l[2]]==N/3){
            int a = l[0]^l[1]^l[2];
            if(a==0){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}