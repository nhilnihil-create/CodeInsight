#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

void Output(const std::vector<std::pair<int, int> >& List)
{
    for(std::vector<std::pair<int, int> >::const_iterator It = List.begin();
        It != List.end();
        ++It)
    {
        std::cout << " " << It->second;
    }
    std::cout << std::endl;
}

int main()
{
    std::string l;
    std::cin >> l;

    std::vector<int> S1;
    std::vector<std::pair<int, int> > S2;
    int sum = 0;
    for(int i = 0; i < l.size(); ++i){
        if(l[i] == '\\'){
            S1.push_back(i);
        }else
        if(l[i] == '/' && S1.empty() == false){
            int j = S1.back(); S1.pop_back();
            int a = i - j;
            sum += a;
            
            while( S2.empty() == false && S2.back().first > j){
                a += S2.back().second; S2.pop_back();
            }
            S2.push_back(std::pair<int, int>(j, a));
        }
    }
    std::cout << sum << std::endl;
    std::cout << S2.size();
    Output(S2);
    return 0;
}