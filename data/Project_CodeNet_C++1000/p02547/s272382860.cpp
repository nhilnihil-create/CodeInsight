#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=150;
pair<int , int > p[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        p[i].F=x;
        p[i].S=y;
    }
    bool q=0;
    for(int i=0;i<n-2;i++){
        if(p[i].F == p[i].S && p[i+1].F == p[i+1].S && p[i+2].F==p[i+2].S){
            q=1;
        }
    }
    if(q){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
