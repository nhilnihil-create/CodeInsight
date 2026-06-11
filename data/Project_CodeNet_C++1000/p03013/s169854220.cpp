#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;
long long int bign = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<bool> bre(n+1,false);
    int a;
    for(int i=0;i<m;i++){
        cin >> a;
        bre.at(a)=true;
    }
    vector<pair<long long int,long long int>> res(n+1,make_pair(0,0));
    // (1段前から, 2段前から直接)
    res.at(0).first=1;
    // res.at(0).second=1;
    if(!bre.at(1))res.at(1).first=1;
    for(int i=2;i<=n;i++){
        
        if(bre.at(i))continue;
        if(bre.at(i-1) && bre.at(i-2)){
            cout << 0 <<endl;
            return 0;
        }
        else if(bre.at(i-1))res.at(i).second=(res.at(i-2).first+res.at(i-2).second)%bign; 
        else if(bre.at(i-2))res.at(i).first=res.at(i-1).second;
        else {res.at(i).first = (res.at(i-1).first+res.at(i-1).second)%bign;
        res.at(i).second= (res.at(i-2).first + res.at(i-2).second)%bign;}
        
    }
    // for(int i=0;i<=n;i++){
    //     cout << res.at(i).first << ","<< res.at(i).second << endl;
    // }
    cout << (res.at(n).first+res.at(n).second)%bign << endl;
    return 0;
}