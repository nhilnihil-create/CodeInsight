#include<iostream>
#include<map>

int main(){
 std::map<int,int> m;
 int a[3][3];
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        std::cin >> a[i][j];
             if(m[a[i][j]]==0)
                 m[a[i][j]]=1;
    }
}

 int n;
 std::cin >> n;
 int b[n];
 for(int i=0;i<n;i++){
    std::cin >> b[i];
}
 for(int k=0;k<n;k++){
    if(m[b[k]]==1){
  for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
          if(b[k]==a[i][j])
              a[i][j]=-1;
         }
      }
   }
}

bool t=0;
if(a[0][0]==-1 && a[0][1]==-1 && a[0][2]==-1) t=1;
else if(a[1][0]==-1 && a[1][1]==-1 && a[1][2]==-1) t=1;
else if(a[2][0]==-1 && a[2][1]==-1 && a[2][2]==-1) t=1;

else if(a[0][0]==-1 && a[1][0]==-1 && a[2][0]==-1) t=1;
else if(a[0][1]==-1 && a[1][1]==-1 && a[2][1]==-1) t=1;
else if(a[0][2]==-1 && a[1][2]==-1 && a[2][2]==-1) t=1;

else if(a[0][0]==-1 && a[1][1]==-1 && a[2][2]==-1) t=1;
else if(a[0][2]==-1 && a[1][1]==-1 && a[2][0]==-1) t=1;

t==1?std::cout << "Yes" : std::cout << "No";

 return 0;
}
