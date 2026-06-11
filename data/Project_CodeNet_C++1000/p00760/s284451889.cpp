#include<iostream>
main(){int y,m,d;for(std::cin>>d;std::cin>>y>>m>>d;printf("%d\n",196490-d))d+=195*--y+y/3*5+19*m+m/2+!(++y%3)*(m-1)/2;}