#include <iostream>
#include<set>
using namespace std;
int main(void){
    // Your code here!
#define ar array

int ar[3][3];
set<int> s;
int count=0,d1=0, d2=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cin>>ar[i][j];
        }
        
 int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    
    for(int i=0;i<3;i++){
        count=0;
        for(int j=0;j<3;j++){
            if(s.find(ar[i][j])!=s.end()){
                count++;
            }
                
        }
        if(count==3)
            {
                cout<<"Yes";
                return 0;
            }
    }
    
    
 for(int i=0;i<3;i++){
     count=0;
        for(int j=0;j<3;j++){
            if(s.find(ar[j][i])!=s.end()){
                count++;
            }
                
        }
        if(count==3)
            {
                cout<<"Yes";
                return 0;
            }
    }    

count=0;
for(int i=0,j=0;i<3&&j<3;i++,j++)
         if(s.find(ar[j][i])!=s.end()){
                count++;
            }
            
 if(count==3)
{
    cout<<"Yes";
    return 0;
}

count=0;
for(int i=0,j=2;i<3&&j>=0;i++,j--)
         if(s.find(ar[i][j])!=s.end()){
                count++;
            }
            
 if(count==3)
{
    cout<<"Yes";
    return 0;
}

cout<<"No";
    
}
