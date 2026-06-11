#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
//O(n^2)
void stupid(){
    int N;
    int cnt;
    std::cin>>N;
    std::vector<unsigned int>A(N);
    for(int i=0;i<N;++i){
        std::cin>>A[i];
    }
    cnt=0;
    for(int i=0;i<N;++i){
        bool flag=1;
        for(int j=0;j<N;++j){
            if(i!=j && A[i]%A[j]==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cnt++;
        }
    }
    std::cout<<cnt;
}

//O(n^2)
void stupid1(){
    int N;
    int cnt;
    std::cin>>N;
    std::vector<unsigned int>A(N);
    for(int i=0;i<N;++i){
        std::cin>>A[i];
    }
    std::sort(A.begin(),A.end());
    cnt=0;
    for(int i=0;i<N;++i){
        bool flag=1;
        for(int j=0;A[j]<=A[i];++j){
            if(i!=j && A[i]%A[j]==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cnt++;
        }
    }
    std::cout<<cnt;
}

void correct(){
    int N;
    // int cnt;
    std::cin>>N;
    std::vector<unsigned int>A(N);
    // std::vector<bool>flags(N,1);
    int startVal;
    for(int i=0;i<N;++i){
        std::cin>>A[i];
    }
    std::sort(A.begin(),A.end());
    std::unordered_map<int,int> maps;
    // for(int i=*(A.begin());i<=A.back();++i){
    for(auto itr=A.begin();itr!=A.end();++itr){
        maps[*itr]++;
    }
    int cnt=0;
    for(int i=0;i<N;++i){
        if(maps[A[i]]==1)
            cnt++;

        for(int j=A[i];j<=A.back();j=j+A[i]){
            maps[j]=0;
        }
    }
    std::cout<<cnt;
}

int main(){
    // stupid();
    // stupid1();
    correct();
    return 0;
}