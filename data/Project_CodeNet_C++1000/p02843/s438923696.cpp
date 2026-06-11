#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int X;
    cin >> X;
    int Ans=0;
    if(X<100)Ans = 0;
    else if(2000<=X)Ans =1;
    else{
        for(int a=0;a<20;a++){
            for(int b=0;b<20;b++){
                for(int c=0;c<20;c++){
                    for(int d=0;d<20;d++){
                        for(int e=0;e<20;e++){
                            for(int f=0;f<20;f++){
                                int A = 100*a+101*b+102*c+103*d + 104*e + 105*f;
                                if(A==X)Ans =1;
                            }
                        }
                    }
                }
            }
        }
        
    }
    cout << Ans << endl;
}