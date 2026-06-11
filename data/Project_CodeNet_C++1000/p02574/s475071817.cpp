#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct primegroup{
    vector<int> r;

    primegroup(int n){
        r = vector<int>(1000001, 0);
        r[1] = n;
    }

    void unite(int x){
        for(int i=2; i*i<=x; i++){
            if(x%i != 0) continue;

            while(x%i == 0){
                x/=i;
            }

            r[i]++;
        }    

        if(x != 1) r[x]++;
    }

    void judge(){
        int maxval=0;

        for(auto i=2; i<r.size(); i++){
            if(r[i]>0)
                maxval = max(maxval, r[i]);
        }

        if(maxval <= 1)
            cout<<"pairwise coprime"<<endl;
        else if(maxval != r[1])
            cout<<"setwise coprime"<<endl;
        else
            cout<<"not coprime"<<endl;
        
    }
};

int main(){
    int n;
    cin>>n;
    primegroup pg(n);

    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        pg.unite(m);
    }

    pg.judge();
    
    return 0;
}
