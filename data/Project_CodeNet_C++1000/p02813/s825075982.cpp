#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> p(n), q(n), r(n);
    for(int i=0; i<n; ++i){cin >> p[i];}
    for(int i=0; i<n; ++i){cin >> q[i];}
    for(int i=0; i<n; ++i){r[i] = i+1;}
    int pn, qn;
    int cnt = 0;
    do{
        int pm = 0; int  qm = 0;
        for(int i=0; i<n; ++i){
          	
            if(p[i]!=r[i]){continue;}
            else if(p[i]==r[i]){
                pm++; 
                if(pm==n){pn = cnt; break;}
            }
        }
        for(int i=0; i<n; ++i){
            if(q[i]!=r[i]){continue;}
            else if(q[i]==r[i]){
                qm++; 
                if(qm==n){qn = cnt; break;}
            }
        }
        cnt++;
    }while(next_permutation(r.begin(), r.end()));
    cout << abs(pn-qn) << endl;
    return 0;
}