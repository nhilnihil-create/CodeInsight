
#include<bits/stdc++.h>
using namespace std;


bool fun(int x, unordered_map<int, int> &m){
    
    if(x%2==0){
       if(m[2]==0){
            m[2] = 1;
            while(x%2==0){
                x = x/2;
            }
        }else{
            return false;
        }
        
    }
    
    for(int i = 3;i<=sqrt(x);i+=2){
        if(x%i==0){
            if(m[i]==0){
                m[i] = 1;
                
                while(x%i==0){
                    x = x/i;
                }


            }else{
                return false;
            }

        }
    }
    
    if(x > 2){
        if(m[x] == 0){
            m[x] = 1;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
        
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n;
        cin>>n;
        unordered_map<int, int> m;
        int arr[n];
        bool res = true;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }

        for(int i = 0;i<n;i++){
            if(!fun(arr[i], m))
            {
                res = false;
                break;
            }    
        }

        if(res){
            cout<<"pairwise coprime";
            return 0;
        }else{
            int g = arr[0];
            for(int i = 1;i<n;i++){
                
                g = __gcd(g, arr[i]);
            }

                if( g == 1 ){
                    cout<<"setwise coprime";
                    return 0;
                }
        }
        cout<<"not coprime";

        return 0;
}