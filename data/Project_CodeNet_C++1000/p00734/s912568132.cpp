#include<iostream>
#include<algorithm>
using namespace std;
int s[100], t[100];

int main(){

    while(1){

        int n, m;
        cin>> n>> m;
        if(n==0&&m==0) break;
        for(int i=0; i<n; i++) cin>> s[i];
        for(int i=0; i<m; i++) cin>> t[i];

        int mi=300;
        vector<pair<int, int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                swap(s[i], t[j]);
                int s1=accumulate(s, s+n, 0);
                int s2=accumulate(t, t+m, 0);
                if(s1==s2){
                    if(s[i]+t[j]<mi){
                        ans.push_back(make_pair(t[j], s[i]));
                        mi=s[i]+t[j];
                    }
                }
                swap(s[i], t[j]);
            }
        }
        if(ans.size()==0){
            cout<< -1<< endl;
        }else{
            cout<< ans[0].first<< " "<< ans[0].second<< endl;
        }
        
    }
    
    return 0;
}