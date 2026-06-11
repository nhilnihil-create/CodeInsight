#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    vector<pair<int,int>> a(5);
    for(int i=0;i<2;i++){
        a.at(i) = make_pair(i+1,i+2);
        a.at(i+3) = make_pair(i+N+1,i+N+2);
    }
    a.at(2) = make_pair(3, 1+N);
    if(N<3){
        cout<<"No"<<endl;
    }
    else if(N%2!=0){
        cout<<"Yes"<<endl;
        for(int i=4;i<N;i+=2){
            a.push_back(make_pair(i, i+1));
            a.push_back(make_pair(i+N,i+1+N));
            a.push_back(make_pair(i+1, 1+N));
            a.push_back(make_pair(i+N,1+N));
        }
        for(int i=0;i<a.size();i++){
            cout<<a.at(i).first<<" "<<a.at(i).second<<endl;
        }
    }
    else{
        int c=N;
        while(true){
            if(c%2 !=0) break;
            else{
                c/=2;
                if(c==1){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Yes"<<endl;
        for(int i=4;i<=N-1;i+=2){
            a.push_back(make_pair(i, i+1));
            a.push_back(make_pair(i+N,i+1+N));
            a.push_back(make_pair(i, 1+N));
            a.push_back(make_pair(i+N+1,1+N));
        }
        
        bool b = false;
        for(int i=2;i<N;i++){
            for(int j=i+1;j<N;j++){
                int m,l,k; m=i; l=j; k=N;
                //最大値は言わずもがなk
                int n=1;
                while(true){
                    if((n%2 + m%2 + l%2 + k%2)%2 != 0) break;
                    
                    else{
                        n/=2;m/=2;l/=2;k/=2;
                    }
                    
                    if(k == 0){
                        if(i==2)i+=N;
                        else if(i%2!=0 && i != 3) i+= N;
                        if(j%2!=0&&j!=3)j+=N;
                        a.push_back(make_pair(N,i));
                        a.push_back(make_pair(2*N,j));
                        b = true;
                        break;
                    }
                }
                if(b) break;
            }
            if(b) break;
        }
        
        for(int i=0;i<a.size();i++){
        cout<<a.at(i).first<<" "<<a.at(i).second<<endl;
        }
    }
}
