#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a,b,c,k;
	string ans="No";
    cin>>a>>b>>c;
    cin>>k;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k-i;j++){
            for(int l=0;l<=k-i-j;l++){
                int A,B,C;
                A=a*pow(2,i);
                B=b*pow(2,j);
                C=c*pow(2,l);
                if(C>B&&B>A){
                  
                    ans="Yes";
                }
            }
        }
    }
    cout<<ans;

}