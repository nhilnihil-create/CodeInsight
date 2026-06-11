#include <bits/stdc++.h>
using namespace std;
 

 
int main() {

    int64_t n,k;
    cin>>n>>k;


    vector<int64_t> A(n);
    for(int i=0;i<n;i++){
        cin>>A.at(i);
        A.at(i)--; // 0～にする。
    } 


    vector<int64_t> visit(n);
    int64_t next=0;
    int64_t loop_length=1;
    bool loop_flg=false;
    for(int i=0;i<n;i++){
//        cout<<next<<" ";
        visit.at(next) = i+1;
        next = A.at(next);

        if(visit.at(next) != 0){
            loop_length = i+1 - visit.at(next)+1;
            loop_flg=true;
            break;
        }
    }

    int64_t index;
    if(k>n)
        index = (k-visit.at(next))%loop_length;
    else{
        index=k-1;
        next=0;
    }
//    cout<<"loop_length="<<loop_length<<endl;
//    cout<<"index="<<index<<endl;
    for(int i=0;i<index;i++){
        next = A.at(next);
    }

//    cout<<endl;
    cout<<++A.at(next)<<endl;

 	return 0;
}
