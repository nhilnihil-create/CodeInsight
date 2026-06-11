#include<iostream>
using namespace std;
long long A,B,C,K,k;
int main(){
    cin>>A>>B>>C>>K;
    while(A>=B){B<<=1LL;k++;}
     while(B>=C){C<<=1LL;k++;}
    cout<<(k<=K?"Yes":"No")<<endl;
    return 0;
}