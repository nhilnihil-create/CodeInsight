#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    int a[13]={1,2,3,5,7,11,13,15,17,19,23,29,31};
    int b[9]={4,6,9,10,14,21,22,25,26};
    int c[2]={28,30};
    int d[5]={8,12,18,20,27};
    int e[1]={16};
    int f[1]={24};
    int h[1]={32};
    for(int i : a){
        if(i==k){
            cout<<"1\n";
            break;
        }
    }
    for(int i : b){
        if(i==k){
            cout<<"2\n";
            break;
        }
    }
    for(int i : c){
        if(i==k){
            cout<<"4\n";
            break;
        }
    }
    for(int i : d){
        if(i==k){
            cout<<"5\n";
            break;
        }
    }
    for(int i:e){
        if(i==k){
            cout<<"14\n";
            break;
        }
    }
    for(int i: f){
        if(i==k){
            cout<<"15\n";
            break;
        }
    }
    for(int i : h){
        if(i==k){
            cout<<"51\n";
            break;
        }
    }

}