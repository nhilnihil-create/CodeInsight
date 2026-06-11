#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int Parent;
    int Depth;
    std::vector<int> Child;
};

int main(void){
    int Num;
    std::cin >> Num;
    
    std::vector<Node> List;
    List.resize(Num);
    
    for(int i = 0; i < Num; i++){
        List[i].Parent = -1;
    }
    
    int Id, Jisu, Temp;
    
    //?????¨????????????
    for(int i = 0; i < Num; i++){
        std::cin >> Id;
        std::cin >> Jisu;
        
        List[Id].Depth = 0;

        List[Id].Child.clear();
        for(int j = 0; j < Jisu; j++){
            std::cin >> Temp;
            List[Id].Child.push_back(Temp);
            List[Temp].Parent = Id;
        }
    }
    
    //Depth
    for(int i = 0; i < Num; i++){
        int depth = 0;
        int ParentNumber = List[i].Parent;
        while(ParentNumber != -1){
            ParentNumber = List[ParentNumber].Parent;
            depth++;
        }
        List[i].Depth = depth;
    }
    
    
    //??????
    for(int i = 0; i < Num; i++){
        std::cout << "node ";
        std::cout << i;
        std::cout << ": parent = ";
        std::cout << List[i].Parent;
        std::cout << ", depth = ";
        std::cout <<  List[i].Depth;
        std::cout << ", ";
        if(List[i].Child.size() > 0){
            if(List[i].Parent == -1){
                std::cout << "root, [";
            } else{
                std::cout << "internal node, [";
            }
            for(int j = 0; j < List[i].Child.size(); j++){
                if(j > 0)   std::cout << ", ";
                std::cout << List[i].Child[j];
            }
            std::cout << "]";
        } else{
            if(Num > 1){
                std::cout << "leaf, []";
            } else{
                std::cout << "root, []";
            }
        }
        std::cout << std::endl;
    }
}