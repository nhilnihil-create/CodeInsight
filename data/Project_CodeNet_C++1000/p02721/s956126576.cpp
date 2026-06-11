#include<bits/stdc++.h> 
using namespace std;
int main(){
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> L1, L2;
    int last = -1e9;
    for(int i=0; i<N; i++){
        if(S[i] == 'o' && last+C < i){
            last = i;
            L1.push_back(i);
        }
        if(L1.size() == K) break;
    }
    int stock = 1e9;
    for(int i=N-1; i>=0; i--){
        if(S[i] == 'o' && stock >= C){
            L2.push_back(i);
            stock = 0;
        }else{
            stock++;
        }
        if(L2.size() == K) break;
    }
    reverse(L2.begin(), L2.end());
    for(int i=0; i<K; i++) if(L1[i] == L2[i]) cout << L1[i]+1 << endl;
    return 0;
}