#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, x, y, dist;
    cin>>n>>x>>y;
    int ct[n];
    for(int i = 0; i < n; i++){
        ct[i] = 0;
    }
    for(int d = 1; d < n; d++)
    {
        for(int i = 1; i+d <= n; i++){
            int a = i, b = i+d;
            if((a <= x && b <= x) || (a >= y && b >= y)){
                dist = d;
            }
            else if(a <= x && b >= y){
                dist = x - a + b - y + 1;    
            }else if(a >= x & b <= y){
                int t1, t2;
                t1 = d;
                t2 = 1 + (a-x) + (y-b);
                dist = min(t1, t2);
            }else if(a <= x && b >= x && b <= y){
                int t1, t2;
                t1 = d;
                t2 = (x-a)+1+(y-b);
                dist = min(t1, t2);
            }else{
                int t1, t2;
                t1 = d;
                t2 = (b-y)+1+(a-x);
                dist = min(t1, t2);
            }
            ct[dist]++;
        }
    }
    for(int i = 1; i < n; i++){
        cout<<ct[i]<<endl;
    }
    return 0;
}