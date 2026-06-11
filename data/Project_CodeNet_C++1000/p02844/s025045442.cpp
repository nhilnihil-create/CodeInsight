#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S; 
    vector<int> min_max_keta(20,-1);
    for(int i=0; i<(int)S.size(); i++){
        int k = S.at(i) - '0';
        if(min_max_keta.at(2*k) == -1){
            min_max_keta.at(2*k) = 1;
        }
        else{
            min_max_keta.at(2*k+1) = i;
        }
    }
    int ans = 0;
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                /*
                if(min_max_keta.at(2*i)==-1||min_max_keta.at(2*j)==-1||min_max_keta.at(2*k)==-1){
                    continue;
                }
                if(min_max_keta.at(2*i) < min_max_keta.at(2*k+1)){
                    if(min_max_keta.at(2*j+1)<min_max_keta.at(2*i)){
                        continue;
                    }
                    if(min_max_keta.at(2*k+1)<min_max_keta.at(2*j)){
                        continue;
                    }
                    cout << i << j << k << endl;
                    ans++;
                }
                */
               int check[3] = {i, j, k};
               int f = 0;
               for(int l=0; l<N; l++){
                   if (S.at(l) == check[f] + '0') f++;
                   if (f==3) break;
               }
               if(f == 3) ans++;
            }
        }
    }
    cout << ans << endl;
}