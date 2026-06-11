#include<iostream>

using namespace std;

int n;


int CheckAnswer(int m,int k,int *vec){
    if(k==0){
        return 1;
    }else if(m>=n){
        return 0;
    }else{
        int res= CheckAnswer(m+1,k,vec)||CheckAnswer(m+1,k-vec[m],vec);
        return res;
    }
}



int main(){
    cin>>n;
    int vec[n];
    for(int i=0;i<n;++i){
        int m;
        cin>>m;
        vec[i]=m;
        
    }

    int q;
    cin>>q;
    int l;
    for(int j=0;j<q;++j){
        cin>>l;
        if(CheckAnswer(0,l,vec)==1){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }

}

