 #include<iostream>
 using namespace std;

 int main()
 {
     int a,b,i;

     cin>>a>>b;

     if(a>b){
        for(i=1;i<=a;i++){
            cout<<b;
        }
        cout<<endl;
     }
     else if(a<b){
        for(i=1;i<=b;i++){
            cout<<a;
        }
        cout<<endl;
     }
     else if(a==b){
        for(i=1;i<=b;i++){
            cout<<b;
        }
        cout<<endl;
     }

     return 0;
 }
