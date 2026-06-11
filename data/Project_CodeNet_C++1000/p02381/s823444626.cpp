#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
int main()
{
    int n,m,size;
    double heikin,sum,hensatotal,test,hensa;
    while(true){
    std::vector<int> list={0};
    hensatotal=0;
    sum = 0;
    std::cin >> n;
    if(n==0)break;
    for(int a=0;a<n;a++){
        std::cin >> m;
        list.push_back(m);
        //list[a]=m;
    }
    size = list.size()-1;
    for (int i = 0; i < size+1; i++){
        sum =(sum+list[i])*1.000000000;
    }
//   std::cout << sum << "   " << size<< std::endl;
    heikin=sum/size;
    for (int z = 1; z < size+1; z++){
        test = (list[z]-heikin)*(list[z]-heikin);
//        std::cout << list[z] << "-" << heikin << "   ";
        hensatotal=hensatotal+test;
//        std::cout << hensatotal << std::endl;

    }
    hensa=hensatotal/size;
    hensa=sqrt(hensa);
//    std::cout << std::endl;
//    std::cout << hensatotal << std::endl;
//    std::cout << hensa << std::endl;
    printf("%.8f\n",hensa);
    list.clear();
    list.shrink_to_fit();
    }
    return 0;
}