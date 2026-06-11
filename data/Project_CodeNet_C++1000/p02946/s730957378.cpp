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
    ABC137();
}

void ABC137(){
    int k,x,i;
    cin>>k>>x;
    vector<int> vec;
    vec.push_back(x);
    for(i=1;i<k;i++){
        vec.push_back(x+i);
        vec.push_back(x-i);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<vec.size();i++){
        if(i<vec.size()-1)cout<<vec[i]<<" ";
        else cout<<vec[i]<<endl;
    }
}