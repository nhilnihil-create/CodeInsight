#include <iostream>
#include <queue>
#include <string>

#define INPUT_FROM_FILE (0)

#if INPUT_FROM_FILE
#include <fstream>
#endif

#if INPUT_FROM_FILE
#define IS ifs
#else
#define IS std::cin
#endif

int main(int argc, char **argv){
#if INPUT_FROM_FILE
	std::ifstream ifs = std::ifstream("test.txt");
#endif
	int n = 0;
	int q = 0;
	std::queue<std::pair<std::string, int> > queue;
	std::string name;
	int time = 0;

	IS >> n >> q;
	
	for(int i = 0; i < n; i++){
		IS >> name >> time;
		queue.push(std::pair<std::string, int>(name, time));
	}

	time = 0;
	for(int i = 0; !queue.empty(); i++){
		std::pair<std::string, int> job = queue.front();
		queue.pop();

		if(job.second <= q){
			time += job.second;
			std::cout << job.first << " " << time << std::endl;
		}
		else{
			job.second -= q;
			time += q;
			queue.push(job);
		}
	}
	
	return 0;
}