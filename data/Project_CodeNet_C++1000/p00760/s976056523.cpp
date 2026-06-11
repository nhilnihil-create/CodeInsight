#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int Y[109] ={};
int M[109] ={};
int D[109] ={};

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d %d",&Y[i],&M[i],&D[i]);
    }

    for(int i=0;i<n;i++){
        int ans = 0;
        for(int j = Y[i]+1;j< 1000 ; j++){
            if(j%3 == 0){
                ans += 200;
            }else{
                ans += 195;
            }
        }

        if(Y[i]%3 == 0){
            ans += (10 - M[i]) * 20;
        }else{
            for(int j=M[i]+1;j<=10;j++){
                if(j%2){
                    ans += 20;
                }else{
                    ans += 19;
                }
            }
        }

        if(M[i]%2 || Y[i]%3 == 0){
            ans += 21-D[i];
        }else{
            ans += 20-D[i];
        }
        printf("%d\n",ans);
    }

}
