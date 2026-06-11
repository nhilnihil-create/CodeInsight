#include <bits/stdc++.h>
using namespace std;
using pib = pair<int, int>;

bool bitget(int a,int b){
    return a&(1<<b);
}

 
int main (){
    int N;
    cin >> N;
    vector<vector<pib>> A(N);
    for(int i=0;i<N;i++){
        int j;
        cin >> j;
        A[i]=vector<pib>(j);
        for(pib &i:A[i])cin >> i.first >> i.second;
    }
    
    int maxc=0;
    for(int i=0;i<1<<N;i++){
        int count0=0,cc=0;
        for(vector<pib> j:A){
            int count1=0;
            for(pib k:j){
                if(bitget(i,k.first-1)!=k.second)break;
                count1++;
            }
            
            if((count1==j.size())&&bitget(i, cc))count0++;
            else if(bitget(i, cc))goto skip;
            
            cc++;
        }
        
        maxc=max(maxc,count0);
        
    skip:;
        
    }
    
    cout << maxc << endl;
}
