#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;
struct Zalgorithm{
    vector<int> Z;
    Zalgorithm(string s){
        Z.resize(s.size());
        Z[0]=s.size();
    }

    void Zeach(string s){
        int i=1,j=0;
        while(i<Z[0]){
            while(i+j<Z[0]&&s[j]==s[i+j]) j++;
            Z[i]=j;
            if(j==0){
                i++;
                continue;
            }
            int k=1;
            while(k+Z[k]<j){
                Z[i+k]=Z[k];
                k++;
            }
            i+=k;
            j-=k;
        }
        return;
    }

    int Zmax(string s){
        Zeach(s);
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int can=min(i,Z[i]);
            ans=max(ans,can);
        }
        return ans;
    }
};
int main(){
    int n;
    string s;
    cin >> n >> s;
    int fin=0;
    rp(i,n){
        Zalgorithm zal(s);
        int cand=zal.Zmax(s);
        fin=max(fin,cand);
        s=s.substr(1,s.size()-1);
    }
    cout << fin << endl;
    return 0;
}