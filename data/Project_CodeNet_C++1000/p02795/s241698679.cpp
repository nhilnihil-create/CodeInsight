#include<bits/stdc++.h>
using namespace std;

int main(void){
   int H,W,N;
   cin>>H>>W>>N;
   cout<<ceil((double)N/max((double)H,(double)W))<<endl;
   return 0;
}
