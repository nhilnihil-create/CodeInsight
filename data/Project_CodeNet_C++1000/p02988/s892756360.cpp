#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC130(void);
void ABC131(void);
void ABC132(void);
void ABC133(void);
void ABC134(void);
void ABC135(void);
void ABC136(void);
void ABC137(void);
void ABC138(void);
void ABC139(void);

int main(void){
    ABC132();
}

void ABC132(){
    int n,i,ans=0;
    cin>>n;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    for(i=1;i<n-1;i++){
        if(vec[i]>vec[i-1]&&vec[i]<vec[i+1])ans++;
        if(vec[i]<vec[i-1]&&vec[i]>vec[i+1])ans++;
    }
    cout<<ans<<endl;
}