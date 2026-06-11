#include <bits/stdc++.h>
using namespace std;

int a,b,llo,lo;
bool x[100][10000],y[100],dp[100][10000],sdp[100][10000];

int yoko(int oop){
    for(int e=0;e<b;e++){
            int ddf=0;
        for(int g=0;g<a;g++){
            if(dp[g][e]==1){ddf++;}
        }
        if(ddf>a/2){
                        for(int g=0;g<a;g++){
            if(dp[g][e]==0){dp[g][e]=1;}else
            if(dp[g][e]==1){dp[g][e]=0;}
        }

        }
    }

}


int cou(){
    llo=0;
    for(int m=0;m<a;m++){
        for(int c=0;c<b;c++){
            dp[m][c]=x[m][c];
        }
    }

    for(int m=0;m<a;m++){
        if(y[m]==1){
            for(int c=0;c<b;c++){
                if(x[m][c]==0){dp[m][c]=1;}else
                if(x[m][c]==1){dp[m][c]=0;}
            }
        }
    }

    yoko(0);

    for(int m=0;m<a;m++){
        for(int c=0;c<b;c++){
            if(dp[m][c]==0){llo++;}
        }
    }
    if(lo<=llo){lo=llo;
        for(int m=0;m<a;m++){
            for(int c=0;c<b;c++){
                sdp[m][c]=dp[m][c];
            }
        }
    }


}

int gyou(int f){
    if(f>=a){ cou(); return 0;}
    y[f]=0;
    gyou(f+1);
    y[f]=1;
    gyou(f+1);
}


int main(){
    while(1){
        cin>>a>>b;
        if(a+b==0){break;}
        if(a==10&&b==0){break;}
    for(int q=0;q<a;q++){
        for(int g=0;g<b;g++){
            cin>>x[q][g];
        }
    }
    gyou(0);

    cout<<lo<<endl;
    }




}