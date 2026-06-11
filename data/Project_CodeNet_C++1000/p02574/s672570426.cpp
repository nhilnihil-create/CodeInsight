#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
int ct[MAX];

int main() 
{
    int n,x;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> x;
        
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                ct[j]++;
                while(x%j==0){
                    x/=j;
                }
            }
        }
        if(x>1) ct[x]++;
    }
    
    bool isPairwise = true;
    for(int i=2;i<MAX;i++){
        if(ct[i]>=2){
            isPairwise = false;
            break;
        }
    }
    
    if(isPairwise) {
        cout<<"pairwise coprime\n";
        return 0;
    }
    bool isSetwise = true;
    for(int i=2;i<MAX;i++){
        if(ct[i]==n){
            isSetwise = false; 
            break;
        }
    }
    
    if(isSetwise) {
        cout<<"setwise coprime\n";
        return 0;
    }
    
    cout<<"not coprime\n";
    return 0;
}