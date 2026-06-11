 #include<iostream>
 using namespace std;

 int main()
 {
     int n,i,j,k,c;
     cin>>n;
     int ara[n];

     for(i=0;i<n;i++){
        cin>>ara[i];
     }
     c = ara[0];
     k = 1;;
     for(i=1;i<n;i++){
       if(ara[i]<=c){
        k++;
        c = ara[i];
       }
    }

     cout<<k<<endl;

     return 0;
 }
