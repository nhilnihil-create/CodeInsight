/*#include<iostream>
int main(){
int a,b;
int x,y,z,count;
while(true){
std::cin>>a>>b;
count=0;
if(a==0&&b==0)break;
x=1;y=0;z=0;
for(int i=1;i<=a-2;i++){
for(int j=i+1;j<=a-1;j++){
for(int k=j+1;k<=a;k++){
if(i+j+k==b){
count++;
break;
}
}
}
}
std::cout<<count<<std::endl;
    }

    return 0;

}*//*
#include<iostream>
int main(){
    int a,count=0,ans=0;
    std::cin>>a;
    for(int i=1;i<=a;i+=2){
        count=0;
        for(int j=1;j<=i;j++){
            if(i%j==0)count++;
            if(count>8)break;
        }
//        std::cout<<"i:"<<i<<" count:"<<count<<std::endl;
        if(count==8)ans++;
        
    }
    std::cout<<ans<<std::endl;
    return 0;
}
#include<iostream>
#include<string>
int main(){
  std::string str;
  std::cin>>str;
    int count=0;
  for(int i=0;i<str.length();i++){
      int sub=0;
      for(int j=i;j<str.length();j++){
          if(str[j]=='A'||str[j]=='G'||str[j]=='C'||str[j]=='T'){
              sub++;
          }else break;
      }
      count=std::max(count,sub);
  }
    std::cout<<count<<std::endl;
    return 0;
}*/
#include<iostream>

int main(){
  long long int M,c,d,ans,count;
  std::cin>>M;
  ans=0;
//  long long int sub=0;
    count=0;
  for(long long int i=0;i<M;i++){
    std::cin>>d>>c;
    ans+=c;
    count+=c*d;
  }
//    long long int waru=10;
//    long long int count_b=count;
    /*while(true){
        count_b=count_b+count/waru;
        waru*=10;
        if(waru>count_b||waru>100000000000000000)break;
    }*/
  ans=ans+(count-1)/9-1;
  std::cout<<ans<<std::endl;
  return 0;
}
