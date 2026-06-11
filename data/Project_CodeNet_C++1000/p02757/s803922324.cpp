#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    int n,p;
    string s;
    // vector<int> modarray(n+1,0);
    
    cin >> n >> p >> s;
    if(p==2 || p==5){
        long long int res=0;
        for(int i=0;i<n;i++){
            if((s.at(i)-'0')%p==0){
                res+=(i+1);
            }
        }
        cout << res << endl;
        return 0;
    }

    vector<long long int> modlist(p,0);
    modlist.at(0)=1;
    // mod10=10%p;
    int mod10n=1,temp=0;
    for(int i=1;i<n+1;i++){
        
        temp=(temp+(s.at(n-i)-'0')*mod10n)%p;
        modlist.at(temp)++;
        mod10n=(10*mod10n)%p;
    }
    long long int res=0;
    for(int i=0;i<p;i++){
        if(modlist.at(i)>=2)
        res+= (modlist.at(i)*(modlist.at(i)-1))/2;
    }
    cout << res << endl;
    return 0;
}