#include <bits/stdc++.h>
int N,i,b,d;main(){for(std::cin>>N;i<N;i++){char c;std::cin>>c;c-='1';if(c==1)b=-1e9;if(((N-1)&i)==i)d+=c,b+=c/2;}std::cout<<(b>=0?2*(b%2):d%2);}