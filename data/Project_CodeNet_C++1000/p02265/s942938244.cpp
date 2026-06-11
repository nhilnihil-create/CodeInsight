#include <iostream>
#include <deque>

int main(int argc, char const *argv[]){
	
	int N;
	std::deque<int> que;
	std::cin >> N;
	std::string cmd;
	int key;

	for (int i = 0; i < N; ++i){
		if(std::cin >> cmd){
			if(cmd=="insert"){
				std::cin >> key;
				que.push_front(key);
			}else if(cmd=="delete"){
				std::cin >> key;
				for (int j = 0; j < que.size(); ++j){
					if(que[j]==key){
						que.erase(que.begin()+j);
						break;
					}
				}
			}else if(cmd=="deleteFirst"){
				que.pop_front();
			}else if(cmd=="deleteLast"){
				que.pop_back();
			}else{
				// exception
			}
		}
	}
	
	for (int i = 0; i < que.size(); ++i){
		std::cout << que[i];
		if(i<que.size()-1) std::cout << " ";
	}
		std::cout << std::endl;
	
	return 0;
}
