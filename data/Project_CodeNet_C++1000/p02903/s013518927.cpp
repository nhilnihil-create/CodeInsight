#include<bits/stdc++.h>
#include<string>

signed main() {
  int h,w,a,b;
    scanf("%d%d%d%d",&h,&w,&a,&b);
    	std::string s(a,'0');
    	std::string t(w-a,'1');
  		std::string S(a,'1');
  		std::string T(w-a,'0');
  for(int i=0;i<h;++i){
    if(i<b){
    	printf("%s%s\n",s.c_str(),t.c_str());
    }
    else{
    	printf("%s%s\n",S.c_str(),T.c_str());
    }
  }
}
